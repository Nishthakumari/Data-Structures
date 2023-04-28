https://aaronice.gitbook.io/lintcode/sweep-line/meeting-rooms

public boolean canAttendMeetings(Interval[] intervals) {
    // Sort the intervals by start time
    Arrays.sort(intervals, (x, y) -> x.start - y.start);
    for (int i = 1; i < intervals.length; i++)
        if (intervals[i-1].end > intervals[i].start)
            return false;
    return true;
}
