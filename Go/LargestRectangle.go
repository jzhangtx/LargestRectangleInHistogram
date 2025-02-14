package main

import "fmt"

func GetArrayFromInput(count int, prompt string) []int {
	if count == 0 {
		return []int{}
	}

	fmt.Print(prompt)

	v := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&v[i])
	}

	return v
}

func GetArea(heights []int, index int) int {
	area := heights[index]
	height := heights[index]
	for i := index + 1; i < len(heights); i++ {
		height = min(height, heights[i])
		if height == 0 {
			break
		}
		area = max(area, (i-index+1)*height)
	}

	return area
}

func GetLargestArea(heights []int) int {
	maxArea := 0

	for i := 0; i < len(heights); i++ {
		maxArea = max(GetArea(heights, i), maxArea)
	}

	return maxArea
}

func main() {
	for {
		fmt.Print("Number of heights: ")
		var count int
		fmt.Scan(&count)
		if count == 0 {
			break
		}

		heights := GetArrayFromInput(count, "Please enter the heights: ")
		area := GetLargestArea(heights)
		fmt.Print("The largest rectangle in the histogram is ")
		fmt.Println(area)
	}
}
