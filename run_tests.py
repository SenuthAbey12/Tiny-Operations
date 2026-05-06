#!/usr/bin/env python3
import os
import subprocess
import sys

def run_compiler(abs_filepath):
    # We must run the tools from the 'tiny' directory because they expect to read/write
    # intermediate files (_TREE, _CODE, etc.) in the current working directory.
    
    # 1. Parse
    with open(abs_filepath, 'r') as f:
        parse_proc = subprocess.run(
            ['./parser/parse'], 
            stdin=f, 
            stdout=subprocess.DEVNULL, 
            stderr=subprocess.DEVNULL
        )
        if parse_proc.returncode != 0:
            return False
            
    # 2. Constrain
    # Wrap in bash with an extra command to force a fork, so bash doesn't use exec.
    # This prevents the parent PID from being the Python script!
    constrain_proc = subprocess.run(
        ['bash', '-c', './Constrain; exit $?'], 
        stdout=subprocess.DEVNULL, 
        stderr=subprocess.DEVNULL
    )
    if constrain_proc.returncode != 0:
        return False
        
    # 3. CodeGen
    codegen_proc = subprocess.run(
        ['bash', '-c', './CodeGen; exit $?'], 
        stdout=subprocess.DEVNULL, 
        stderr=subprocess.DEVNULL
    )
    if codegen_proc.returncode != 0:
        return False

    return True

def main():
    base_dir = os.path.abspath(os.path.dirname(__file__))
    tiny_dir = os.path.join(base_dir, 'tiny')
    
    test_progs_dir = os.path.join(tiny_dir, 'test-progs')
    tests_dir = os.path.join(tiny_dir, 'tests')

    # Change working directory to tiny so the compiler tools can generate their files there
    os.chdir(tiny_dir)

    passed = 0
    failed = 0
    
    def test_file(filepath, expect_success):
        nonlocal passed, failed
        # Use relative path for cleaner output logs
        display_name = os.path.relpath(filepath, base_dir)
        success = run_compiler(filepath)
        
        if success == expect_success:
            print(f"[PASS] {display_name}")
            passed += 1
        else:
            print(f"[FAIL] {display_name} (Expected {'Success' if expect_success else 'Failure'}, got {'Success' if success else 'Failure'})")
            failed += 1

    # 1. Test files in tiny/test-progs
    print("Running tests in tiny/test-progs...")
    if os.path.exists(test_progs_dir):
        for f in sorted(os.listdir(test_progs_dir)):
            if not (f.startswith("pr1") or f.startswith("pr2") or f.startswith("pr3")):
                continue
            filepath = os.path.join(test_progs_dir, f)
            if not os.path.isfile(filepath):
                continue
                
            # If the filename contains '.c', it should compile successfully
            if '.c' in f:
                test_file(filepath, True)
            # If the filename contains '.e', it should result in an error
            elif '.e' in f:
                test_file(filepath, False)

    # 2. Test files in tiny/tests (p1, p2, etc.)
    print("\nRunning tests in tiny/tests...")
    if os.path.exists(tests_dir):
        for f in sorted(os.listdir(tests_dir)):
            if not f.startswith("p"):
                continue
            filepath = os.path.join(tests_dir, f)
            if not os.path.isfile(filepath):
                continue
            
            # We assume all programs in 'tiny/tests' are correct
            test_file(filepath, True)

    print("\n=== Test Summary ===")
    print(f"Passed: {passed}")
    print(f"Failed: {failed}")
    
    if failed > 0:
        sys.exit(1)
        print("Tests failed")
    else:
        sys.exit(0)
        print("Tests passed")

if __name__ == '__main__':
    main()
