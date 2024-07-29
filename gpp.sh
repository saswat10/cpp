#!/bin/bash

# Get the source file name from the first argument
source_file="$1"

# Check if a source file is provided
if [ -z "$source_file" ]; then
  echo "Error: Please provide a source file name as an argument."
  exit 1
fi

# Extract the filename without extension
filename="${source_file%.*}"

# Compile the code with warnings and generate an executable with the same name
g++ -Wall -Wextra "$source_file" -o "$filename"

# Check the compilation exit status
if [ $? -eq 0 ]; then
  echo "Compilation successful!"

  # Run the program with the assumption that input.txt and output.txt are in the same directory
  ./"$filename" < input.txt > output.txt

  # Alternatively, if the input and output files are in different locations:
  # ./"$filename" < path/to/input.txt > path/to/output.txt

  echo "Program execution complete. Check output.txt."

  # Clean up the executable (optional, comment out if you want to keep it)
  rm -f "$filename"
  echo "Executable '$filename' removed."
else
  echo "Compilation failed."
fi
