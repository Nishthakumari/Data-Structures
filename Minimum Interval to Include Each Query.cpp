//https://www.geeksforgeeks.org/find-the-minimum-range-size-that-contains-the-given-element-for-q-queries/


vector<int> minInterval(vector<vector<int> >& intervals,
						vector<int>& q)
{
	// Store all the queries
	// along with their index
	vector<vector<int> > queries;

	for (int i = 0; i < q.size(); i++)
		queries.push_back({ q[i], i });

	// Sort the vector intervals and queries
	sort(intervals.begin(), intervals.end());
	sort(queries.begin(), queries.end());

	// Max priority queue to keep track
	// of intervals size and right value
	priority_queue<vector<int> > pq;

	// Stores the result of all the queries
	vector<int> result(queries.size(), -1);

	// Current position of intervals
	int i = 0;

	for (int j = 0; j < queries.size(); j++) {

		// Stores the current query
		int temp = queries[j][0];

		// Insert all the intervals whose left value
		// is less than or equal to the current query
		while (i < intervals.size()
			&& intervals[i][0] <= temp) {

			// Insert the negative of range size and
			// the right bound of the interval
			pq.push(
				{ -intervals[i][1] + intervals[i][0] - 1,
				intervals[i++][1] });
		}

		// Pop all the intervals with right value
		// less than the current query
		while (!pq.empty() && temp > pq.top()[1]) {
			pq.pop();
		}

		// Check if the valid interval exists
		// Update the answer for current query
		// in result array
		if (!pq.empty())
			result[queries[j][1]] = -pq.top()[0];
	}
	// Return the result array
	return result;
}

