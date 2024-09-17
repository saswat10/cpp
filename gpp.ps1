# Get the source file name from the first argument
$sourceFile = $args[0]

# Check if a source file is provided
if (!$sourceFile) {
    Write-Error "Error: Please provide a source file name as an argument."
    exit 1
}

# Extract the filename without extension
$filename = $sourceFile.Substring(0, $sourceFile.LastIndexOf('.'))

# Compile the code with warnings and generate an executable with the same name
g++ -Wall -Wextra "$sourceFile" -o "$filename"

# Check the compilation exit status
if ($?) {
    Write-Host "Compilation successful!"

    # Run the program with the assumption that input.txt and output.txt are in the same directory
    &".\$filename" input.txt  output.txt

    # Alternatively, if the input and output files are in different locations:
    # &".\$filename" < "path/to/input.txt" > "path/to/output.txt"

    Write-Host "Program execution complete. Check output.txt."

    # Clean up the executable (optional, comment out if you want to keep it)
    Remove-Item "$filename"
    Write-Host "Executable '$filename' removed."
} else {
    Write-Host "Compilation failed."
}