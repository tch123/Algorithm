#coding: gbk


#===========================================Core Function===========================================
#SelectionSort
def SelectionSort(A):
    for i in range(0 , len(A) - 1):             #For all A element
        min = i                                 #Record the minimum's cursor.Init by i self
        for j in range(i + 1,len(A)):           #For the remaining elements
            if A[j] < A[min]:                   #if there is a smaller one than current min
                min = j                         #Update it
        A[i],A[min] = A[min],A[i]               #Exchange the current i th element with the minimum element

#Invariant:     A[0 ... j-1] keeps in order when 'for' begin
#Begin:         j = 1 . A[0] is in order
#Keep:          when quit from 'while': We get the i: key >= A[i] but key < A[i+1] and A[i+1] have copied to A[i+2]
#               So we put key in A[i+1]. right after a[i]. which makes A[0 ... j-1] keeps invariant next time
#Final:         When Sort ends. final j = len(A) which makes a[0...j-1] = A. i.e : A is sorted! 

#Analysis:
#               Worst               Average             Best        Comment
#Compare:       n(n+1)/2 - 1                                        逆序对数+n-1 = 
#Exchage:       n(n-1)/2                                            n个元素最多可能有1+...+n-1个逆序对
#Time:          O(n^2)              O(n^2)
#Space:         O(1)                O(1)                O(1)
#Stabiliry:     True
#Feature:       只访问当前游标之前的元素。
#Comment:       插入排序需要的交换操作和数组中逆序对的个数相等。需要的比较次数=逆序对数+数组大小n-1。
#               每次最后一次比较是失败的所以+n，第n个元素不用进行比较所以-11


#===========================================Core Function===========================================




#===========================================Core Function===========================================
#InsertionSort
def InsertionSort(A):
    for j in range(1,len(A)):               #For all element in A
        key = A[j]                          #Fetch the key
        i = j - 1                           #Begin from the element ahead of A[j]
        while i >= 0 and  key < A[i]:       #while key is still small. A[i] is bigger
            A[i+1] = A[i]                   #Put A[i] to A[i+1] 
            i = i -1                        # i go ahead
        A[i+1] = key                        #Boundary check: i = -1 . valid

#Invariant:     A[0 ... j-1] keeps in order when 'for' begin
#Begin:         j = 1 . A[0] is in order
#Keep:          when quit from 'while': We get the i: key >= A[i] but key < A[i+1] and A[i+1] have copied to A[i+2]
#               So we put key in A[i+1]. right after a[i]. which makes A[0 ... j-1] keeps invariant next time
#Final:         When Sort ends. final j = len(A) which makes a[0...j-1] = A. i.e : A is sorted! 

#Analysis:
#               Worst               Average             Best        Comment
#Compare:       n(n+1)/2 - 1                                        逆序对数+n-1 = 
#Exchage:       n(n-1)/2                                            n个元素最多可能有1+...+n-1个逆序对
#Time:          O(n^2)              O(n^2)
#Space:         O(1)                O(1)                O(1)
#Stabiliry:     True
#Feature:       只访问当前游标之前的元素。
#Comment:       插入排序需要的交换操作和数组中逆序对的个数相等。需要的比较次数=逆序对数+数组大小n-1。
#               每次最后一次比较是失败的所以+n，第n个元素不用进行比较所以-1

#===========================================Core Function===========================================



#===========================================Core Function===========================================
#MergeSort
def MergeSort(A):
    pass   

def Merge(A,p,q,r):
    n1 = q - p + 1      #Array 1: p ... q
    n2 = r - q          #Array 1:

#Invariant:     A[0 ... j-1] keeps in order when 'for' begin
#Begin:         j = 1 . A[0] is in order
#Keep:          when quit from 'while': We get the i: key >= A[i] but key < A[i+1] and A[i+1] have copied to A[i+2]
#               So we put key in A[i+1]. right after a[i]. which makes A[0 ... j-1] keeps invariant next time
#Final:         When Sort ends. final j = len(A) which makes a[0...j-1] = A. i.e : A is sorted! 

#Analysis:
#               Worst               Average             Best        Comment
#Compare:       n(n+1)/2 - 1                                        逆序对数+n-1 = 
#Exchage:       n(n-1)/2                                            n个元素最多可能有1+...+n-1个逆序对
#Time:          O(n^2)              O(n^2)
#Space:         O(1)                O(1)                O(1)
#Stabiliry:     True
#Feature:       只访问当前游标之前的元素。
#Comment:       插入排序需要的交换操作和数组中逆序对的个数相等。需要的比较次数=逆序对数+数组大小n-1。
#               每次最后一次比较是失败的所以+n，第n个元素不用进行比较所以-1

#===========================================Core Function===========================================