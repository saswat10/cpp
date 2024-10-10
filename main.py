def checksum(num):
  """Calculates the checksum of a number.

  Args:
    num: The number to calculate the checksum for.

  Returns:
    The checksum of the number.
  """

  checksum = 0
  while num > 0:
    digit = num % 10
    checksum += digit
    num //= 10
  return checksum

def calculate_total_effort_saved(files, k):
  """Calculates the total effort saved by avoiding scalability adjustments.

  Args:
    files: A list of integers representing the key values of the files.
    k: The key value that saves effort.

  Returns:
    The total effort saved.
  """

  total_effort_saved = 0
  for file in files:
    if checksum(file) == k:
      total_effort_saved += file
  return total_effort_saved

# Read the input from STDIN
n = int(input())
files = list(map(int, input().split()))
k = int(input())

# Calculate the total effort saved
total_effort_saved = calculate_total_effort_saved(files, k)

# Print the output to STDOUT
print(total_effort_saved)