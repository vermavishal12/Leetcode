# ---------    APPROACH     -----------

# now in order to maximize the answer we are required to find the maxmimum element which is in the range of 0 to 2^50 - 1
# which will result in the maxmimised answer, but if we iterate over each element in the range of 0 to 2^50 - 1 it will lead to TLE
# hence our the solution begins like we store the binary representation of the integers 'a' and 'b' in the array 'A' and 'B' respectively 
# and for each index in the array 'A' and 'B' we check whether both the array contains same value at that index or not
# if yes then we simply assign the ith bit of the x to the xor of A[i] 
# if not so then we check whether which of the i.e. set or unset bit at that index will yield us the maximum product
# this can be done by comparing the sol1 and sol2 value, if sol2 >= sol1 then we set the bit at ith index
# here sol1 is the product of the ((a xor x) * (b xor x)) when the bit is unset
# and sol2 is the product of the ((a xor x) * (b xor x)) when the bit is set


class Solution:
    def maximumXorProduct(self, a: int, b: int, n: int) -> int:
        A = []
        B = [] 
        numa = a
        numb = b

        while numa > 0 :
            A.append(numa % 2)
            numa = numa/2
        
        index = 0
        while numb > 0 :
            B.append(numb % 2)
            numb = numb / 2

        while len(A) < 50:
            A.append(0)
        
        while len(B) < 50:
            B.append(0)
        
        
        i = n-1
        res = 0
        while i >= 0 :
            val = 1 << i
            
            if (A[i] == 0 and B[i] == 0):
                res = res ^ val
            else :
                M = res ^ a 
                N = res ^ b
                sol1 = M * N
                M = (res ^ val ^ a) 
                N = (res ^ val ^ b)
                sol2 = M * N
                if sol1 <= sol2 :
                    res = res^ val 
            i = i-1
        
        M = (res ^ a) 
        N = (res ^ b)
        ans = M * N
        return ans % (1000000007)
        