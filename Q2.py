x=input()
n=input()
a=raw_input()
l = map(int, a.split())
#Binary Search is used for the following 2 funtions, in which run time is O(logn) in worst case
def num1(a,b):
#To find the index of first occurence of x
# a and b are start and end positions of subarray in which we want to find the index of first occurence of x
	m=(b-a)/2+a
	if(l[m]<x):
		if(a==m):
			return a+1
		else:
			return num1(m,b)
	elif(l[m]>x):
		return num1(a,m)
	else:
		if(a!=m):
			return num1(a,m)
		else:
			return a
def num2(a,b):#To find the index of last occurence of x
	m=(b-a)/2+a
	if(l[m]>x):
		if(a==m):
			return a-1
		else:
			return num2(a,m)
	elif(l[m]<x):
		return num2(m,b)
	else:
		if(a==m and l[b]!=x):
			return a
		elif(a==m and l[b]==x):
			return a+1
		else:
			return num2(m,b)
print num2(0,n-1)-num1(0,n-1)+1#Prints frequency of x in the given sequence