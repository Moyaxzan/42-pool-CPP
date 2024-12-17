#!/bin/bash

# Number of runs
runs=1000
total_time=0

for ((i = 1; i <= runs; i++)); do
    # Run the command and capture the output
    output=$(./PmergeMe $(shuf -i 1-10000 -n 3000 | tr "\n" " "))
    
    # Extract the time in microseconds from the last line of the output
    time=$(echo "$output" | tail -n 1 | grep -oP '\d+(?= μs)')
    
    # Add the extracted time to the total_time
    total_time=$((total_time + time))
done

# Calculate the average time
average_time=$((total_time / runs))

# Print the result
echo "Average time to process 3000 elements over $runs runs: $average_time μs"

