//https://www.geeksforgeeks.org/minimum-halls-required-for-class-scheduling/

int minHalls(int lectures[][2], int n)
{
 
    // Initialize a vector of pair, Time, first value
    // indicates the time of entry or exit of a lecture
    // second value denotes whether the lecture starts or
    // ends
    vector<pair<int, int> > Time;
 
    // Store the lecture times
    for (int i = 0; i < n; i++) {
        Time.push_back({ lectures[i][0], 1 });
        Time.push_back({ lectures[i][1], -1 });
    }
 
    // Sort the vector
    sort(Time.begin(), Time.end());
 
    int answer = 0, sum = 0;
 
    // Traverse the Time vector and Update sum and answer
    // variables
    for (int i = 0; i < Time.size(); i++) {
        sum += Time[i].second;
        answer = max(answer, sum);
    }
 
    // Return the answer
    return answer;
}
