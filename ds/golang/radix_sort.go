package main

import (
	"fmt"
	"strconv"
)

func genRadixArr() [][]int {
	radixArr := make([][]int, 10)
	for i := 0; i < 10; i++ {
		var arr []int = []int{}
		radixArr = append(radixArr, arr)
	}
	return radixArr
}

func countingSort(arr []int, digit int) []int {
	sorted := []int{}
	radixArr := genRadixArr()
	for j := range arr {
		ele := strconv.Itoa(arr[j])
		index := len(ele) - digit
		if index > -1 {
			digit, err := strconv.Atoi(string(ele[index]))
			if err != nil {
				panic("Conversion failed")
			}
			radixArr[digit] = append(radixArr[digit], arr[j])
		} else {
			radixArr[0] = append(radixArr[0], arr[j])
		}
	}
	for ele := range radixArr {
		if len(radixArr[ele]) > 0 {
			sorted = append(sorted, radixArr[ele]...)
		}
	}
	return sorted
}

func radixSort(arr []int, maxDigitLength int) []int {
	sorted := arr
	for i := 1; i <= maxDigitLength; i++ {
		sorted = countingSort(sorted, i)
	}
	return sorted
}

func main() {
	var arr []int = []int{9, 10, 13, 0, 3, 1, 7}
	fmt.Println(radixSort(arr, 2))
}
