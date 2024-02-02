from random import randint as rnd
from typing import TypeVar

T = TypeVar('T')

'''***********************************************************************'''
def QuickSortPartition(nums: list[T], left: int, right: int) -> tuple[int]:
    i       = left
    j       = right
    mid     = i + (j - i) // 2
    pivot   = nums[mid]
    
    while i <= j:
        while nums[i] < pivot:
            i = i + 1
        
        while nums[j] > pivot:
            j = j - 1
        
        if i <= j:
            nums[i], nums[j] = nums[j], nums[i]
            i = i + 1
            j = j - 1
    
    return (j, i)

'''****************************************************************'''
def QuickSortFunction(nums: list[T], left: int, right: int) -> None:
    partition       = QuickSortPartition(nums, left, right)
    left_part_max   = partition[0]
    right_part_min  = partition[1]
    
    if left < left_part_max:
        QuickSortFunction(nums, left, left_part_max)
    if right > right_part_min:
        QuickSortFunction(nums, right_part_min, right)

'''*********************************'''
def QuickSort(nums: list[T]) -> None:
    QuickSortFunction(nums, 0, len(nums) - 1)

'''***********************************************************************************'''
def GenerateRandomIntVector(list_size: int, min_value: int, max_value: int) -> list[int]:
    ret = []
    
    for i in range(0, list_size, 1):
        ret.append(rnd(min_value, max_value))
    
    return ret

'''*******************************************'''
def CheckIfListIsSorted(nums: list[int]) -> bool:
    for i in range(0, len(nums) - 1, 1):
        if nums[i] > nums[i + 1]:
            return False
    
    return True

'''*************'''
def main() -> None:
    number_of_tests = 10
    
    test_results = []
    
    for i in range(number_of_tests):
        numbers = GenerateRandomIntVector(1000, 1, 100000)
        
        print("Before sorting: ", numbers)
        
        QuickSort(numbers)
        
        print("After sorting: ", numbers)
        
        current_test_result = True if CheckIfListIsSorted(numbers) else False
        test_results.append(current_test_result)
        
        print("Sort result: ", "OK" if current_test_result else "NOK")
        
    print("Overall result (", number_of_tests, "): ", "OK" if CheckIfListIsSorted(test_results) and test_results[0] == True else "NOK")

'''********************'''
if __name__ == "__main__":
    main()
