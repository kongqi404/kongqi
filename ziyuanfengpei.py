inport numpy as np
w=[[0,0.11,0.13,0.15,0.21,0.24,0.3,0.35],[0,0.12,0.16,0.21,0.23,0.25,0.24,0.34],[0,0.08,0.12,0.2,0.24,0.26,0.3,0.35]]
w = np.array(w)
f=w[0,:]
print(f)
for i in reversed(range(1,8)):
  max1=0
  for j in range(i+1):
    max1=max(max1,w[1,j]+f[i-j])
    f[i]=max1
max1=0
i=7
for j in range(i+1):
  max1=max(max1,w[2,j]+f[i-j])
  f[i]=max1

print(f[7]) 
