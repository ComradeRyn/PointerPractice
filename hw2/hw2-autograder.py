import subprocess

# Make sure the autograder is in the same directory as hw1.c
FILE_NAME = "hw2"

def compile_program():
	compile_result = subprocess.run(["gcc", "-fsanitize=address", FILE_NAME+".c", "-o", FILE_NAME], capture_output=True, text=True)
	if compile_result.returncode != 0:
		print("Compilation failed:", compile_result.stderr)
		return False
	return True

def run_test(test_number, test_input, expected_output):
	process = subprocess.Popen(["./"+FILE_NAME, *(test_input.split(' '))], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
	stdout, stderr = process.communicate()

	print(f"Test Case {test_number}: Input = {test_input}", end=" ")

	if stdout.strip() == expected_output.strip() or stderr.strip() == expected_output.strip():
		print("✓ Passed")
		return True
	else:
		print("✗ Failed")
		print(f"   Expected: {expected_output}")
		print(f"   Got: {stdout.strip() if stdout != '' else stderr.strip()}")
		return False

def main():
	if not compile_program():
		return

	test_cases = [
		(1, "this is an incorrect way to pass arguments", "Usage: ./hw2 {rotateBytes|reverseBytes|bitOr} <parameters...>"),
		(2, "invalidExercise 3", "Usage: ./hw2 {rotateBytes|reverseBytes|bitOr} <parameters...>"),

		(3, "rotateBytes 16909060", "288230376151777795"),
		(4, "rotateBytes 4294967295", "18374686479688400895"),

		(5, "reverseBytes 305419896", "8671175384462524416"),
		(6, "reverseBytes 2863311530", "12297829379609722880"),

		(7, "bitOr 12 15", "15"),
		(8, "bitOr 12384 128391", "128487")
		# Add more test cases as needed
		# NOTE: There is only 1 check for validation...Consider testing other validation that you have implemented
	]

	all_passed = True
	for test_number, test_input, expected_output in test_cases:
		if not run_test(test_number, test_input, expected_output):
			all_passed = False

	if all_passed:
		print("All tests passed successfully!")
	else:
		print("Some tests failed.")

if __name__ == "__main__":
	main()
