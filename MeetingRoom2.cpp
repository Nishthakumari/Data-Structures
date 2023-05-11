//https://www.codingninjas.com/codestudio/problems/meeting-room-ii_893289?leftPanelTab=0

#include <bits/stdc++.h> 
int minRooms(vector<vector<int>> intervals)
{
    // Write your code here
    int n = intervals.size();

    // Storing start time and end time in different arrays.
    int startTime[n];
    int endTime[n];

    for (int i = 0; i < n; i++)
    {
        startTime[i] = intervals[i][0];
        endTime[i] = intervals[i][1];
    }

    sort(startTime, startTime + n);
    sort(endTime, endTime + n);

    int result = 1;
    int roomRequired = 0;

    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (startTime[i] < endTime[j])
        {
            roomRequired++;
            i++;
        }
        else
        {
            roomRequired--;
            j++;
        }
        result = max(result, roomRequired);
    }
    
    return result;
    
}
