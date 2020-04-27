# Notice: You are not allowed to code with python @ NOI contests

N = int(input().strip())

h = list(map(int,input().strip().split()))

LInforH =[N]*10002
RInforH =[-1]*10002

for i,H in enumerate(h):
    if(LInforH[H]==N):
        LInforH[H]=i
    RInforH[H] = i

ans=0

for i in range(10000,-1,-1):
    LInforH[i] = min(LInforH[i],LInforH[i+1])
                
for i in range(10000,-1,-1):
    RInforH[i] = max(RInforH[i],RInforH[i+1])
   
for i in range(10001):
    ans = max(ans,i*(RInforH[i]-LInforH[i]))

    
print(ans)
