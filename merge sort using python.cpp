'''

                            Online Python Compiler.
                Code, Compile, Run and Debug python program online.
Write your code in this editor and press "Run" button to execute it.

'''
a=[]
def sort(f,l):
    if(f<l):
        m=(f+l)//2
        sort(f,m)
        sort(m+1,l)
        merge(f,m,l)
def merge(f,m,l):
    b=[]
    i=f
    j=m+1 
    while(i<=m and j<=l):
        if(a[i]<=a[j]):
            b.append(a[i])
            i+=1 
        else:
            b.append(a[j])
            j+=1 
    if(i<=m):
        while(i<=m):
            b.append(a[i])
            i+=1
    else:
        while(j<=l):
            b.append(a[j])
            j+=1
    k=0;
    for s in range(f,l+1):
        a[s]=b[k];
        k+=1;
n=int(input("enter len of array"))
for i in range(n):
    x=int(input("enter element:"))
    a.append(x)
sort(0,len(a)-1);
print(a)
