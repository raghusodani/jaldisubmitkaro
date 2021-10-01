word=raw_input("enter the word ")
for i in range(0,len+1):
	t=word[i]
	word[i]=word[i+1]
	word[i+1]=t

print(word)
