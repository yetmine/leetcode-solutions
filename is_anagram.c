
int isAnagram(char * s, char * t){
	int hashTable[26] = {0};
	int i = -1;

	while (*s)
	{
		hashTable[*s - 97]++;
		s++;
	}
	while (*t)
	{
		hashTable[*t - 97]--;
		t++;
	}
	while (++i < 26)
		if (hashTable[i] != 0)
			return 0;
	return 1;
}
