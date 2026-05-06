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
    constrain_proc = subprocess.run(
        ['./Constrain'], 
        stdout=subprocess.DEVNULL, 
        stderr=subprocess.DEVNULL
    )
    if constrain_proc.returncode != 0:
        return False
        
    # 3. CodeGen
    codegen_proc = subprocess.run(
        ['./CodeGen'], 
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

    # Test specific files in tiny/tests
    print("\nRunning specific tests (p1, p2, p3) in tiny/tests...")
    target_tests = ['p1', 'p2', 'p3']
    if os.path.exists(tests_dir):
        for f in target_tests:
            filepath = os.path.join(tests_dir, f)
            if os.path.isfile(filepath):
                test_file(filepath, True)
            else:
                print(f"[ERROR] Could not find test file: {filepath}")

    print("\n=== Test Summary ===")
    print(f"Passed: {passed}")
    print(f"Failed: {failed}")
    
    if failed > 0:
        sys.exit(1)
    else:
        sys.exit(0)

if __name__ == '__main__':
    main()
