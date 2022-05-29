class Solution {
public:
    int maxProduct(vector<string>& words) {
	// Create a bit mapping for every word
	unordered_map<string, int> m;
	for (auto word : words)
	{
		int wordId = 0;
		for (auto ch : word)
		{
			wordId |= (1 << (ch - 'a'));
		}
		m[word] = wordId;
	}
    
    // Creat for every pair of words and find the max product
	int result = 0;
	for (int i = 0; i < words.size(); i++)
	{
		for (int j = i + 1; j < words.size(); j++)
		{
            // Check if both the words doesnot have any letter in common
			if ((m[words[i]] & m[words[j]]) == 0)
			{
				int answer = words[i].size() * words[j].size();
				result = max(answer, result);
			}
		}
	}

	return result;
}
};