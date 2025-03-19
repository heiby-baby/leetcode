package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	var tail *ListNode = nil
	var result *ListNode = tail
	if list1 == nil && list2 == nil {
		return nil
	}
	if list1 == nil && list2 != nil {
		return list2
	}
	if list2 == nil && list1 != nil {
		return list1
	}

	for {
		if list1 != nil && list2 != nil {
			if list1.Val < list2.Val {
				if tail == nil {
					tail = &ListNode{}
					tail.Val = list1.Val
					list1 = list1.Next
					result = tail
				} else {
					tail.Next = &ListNode{}
					tail = tail.Next
					tail.Val = list1.Val
					list1 = list1.Next
				}
			} else {
				if tail == nil {
					tail = &ListNode{}
					tail.Val = list2.Val
					list2 = list2.Next
					result = tail
				} else {
					tail.Next = &ListNode{}
					tail = tail.Next
					tail.Val = list2.Val
					list2 = list2.Next

				}
			}
		} else {
			if list1 == nil && list2 == nil {
				return result
			}
			if list1 == nil {
				for {
					if list2 == nil {
						return result
					}
					tail.Next = &ListNode{}
					tail = tail.Next
					tail.Val = list2.Val
					list2 = list2.Next

				}
			} else {
				for {
					if list1 == nil {
						return result
					}
					tail.Next = &ListNode{}
					tail = tail.Next
					tail.Val = list1.Val
					list1 = list1.Next
				}
			}

		}
	}
}

func main() {
	var a *ListNode = &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 4}}}
	var b *ListNode = &ListNode{Val: 1, Next: &ListNode{Val: 3, Next: &ListNode{Val: 4}}}

	c := mergeTwoLists(a, b)
	for {
		if c == nil {
			break
		} else {
			fmt.Print(c.Val)
			c = c.Next
		}
	}
	fmt.Print(c)
}
