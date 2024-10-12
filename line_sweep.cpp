//https://leetcode.com/discuss/study-guide/2166045/line-sweep-algorithms


#include <bits/stdc++.h>

int maximumPopulation(vector<vector<int>>& logs) {
    map<int, int> line;
    for(auto& p : logs){
        ++line[p[0]];
        --line[p[1]];
    }
    int max_p = 0;
    int ans_year;
    int count = 0;
    for(auto& i : line){
        count += i.second;
        if(count > max_p){
            max_p = count;
            ans_year = i.first;
        }
    }
    return ans_year;
}


class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        map<int, int> line;
        for(auto& i : intervals){
            line[i.start]++;
            line[i.end]--;
        }
        int ans = 0;
        int count;
        for(auto& p : line){
            count += p.second;
            ans = max(ans, count);
        }
        return ans;
    }
};


bool book(int start, int end) {
        ++m[start];
        --m[end];
        int count = 0;
        for(auto& i : m){
            count += i.second;
            if(count ==3){
                // we are not going to add this event
                // nullify line 10,11 changes
                --m[start];
                ++m[end];
                return false;
            }
        }
        return true;
    }


 bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    
  int line[52] = {};
for (auto &r : ranges) {
    
    line[r[0]] += 1;
    line[(r[1]+1)] -= 1;
}

for (int i = 1, overlaps = 0; i <= 51; ++i) {
    overlaps += line[i];
    if (i>=left and i <=right and overlaps <= 0)
        return false;
}

return true;
}



class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto cmp = [&](const vector<int>& a, const vector<int>& b){
            
            return a[1] < b[1];  
        };
        sort(points.begin(), points.end(), cmp);
        int prev_end = points[0][1];
        int ans = 1;
        for(int i =1; i < points.size(); ++i){
            if(points[i][0] > prev_end){
                ++ans;
                prev_end = points[i][1];
            }
        }
        return ans;
    }
};


vector<vector<int>> ans;
	
	for(auto &i :  intervals)
	{
		int left = i[0];
		int right = i[1];
		if( (toBeRemoved[0] > right ) or (toBeRemoved[1] < left ))
		{
			ans.push_back({left, right});
		}
		else
		{
			if(left < toBeRemoved[0])
			{
				ans.push_back({left, toBeRemoved[0]});
			}
			if (right > toBeRemoved[1])
			{
				ans.push_back({toBeRemoved[1], right});
			}
		}
	}


vector<vector<int>> ans;
	
	for(auto &i :  intervals)
	{
		int left = i[0];
		int right = i[1];
		if( (toBeRemoved[0] > right ) or (toBeRemoved[1] < left ))
		{
			ans.push_back({left, right});
		}
		else
		{
			if(left < toBeRemoved[0])
			{
				ans.push_back({left, toBeRemoved[0]});
			}
			if (right > toBeRemoved[1])
			{
				ans.push_back({toBeRemoved[1], right});
			}
		}
    }


class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        auto comp = [&](const vector<int>& i, const vector<int>& j){
            if(i[0]==j[0])
                return i[1] > j[1];
            return i[0] < j[0];
        };
        sort(intervals.begin(), intervals.end(), comp);
        ans.push_back(intervals[0]);
        int k =0;
        for(int i =1; i< intervals.size(); ++i){
            if( (intervals[i][0]>= ans.back()[0]) and (intervals[i][1] <= ans.back()[1]))
            {
			   // Scenario 1: Completely covered suppose existing interval in vector is [1, 8] and this ith interval is [2, 6] , this is completely inside i.e. start and end
			   // lies inside , hence this interval is surely removed, count this.
                ++k;
            }
            else if(intervals[i][0] > ans.back()[1]){
			// Scenario 2: Suppose vector has [1, 8]  and ith interval is  [9, 10] , totallly unrelated, so push this interval in vector as this is going to be used next time.
                ans.push_back(intervals[i]);
            }
            else if ((intervals[i][0] > ans.back()[0]) and (intervals[i][0] <= ans.back()[1]) )
			    // Scenario 3: vector has [1, 8] and ith interval is  [5, 10], so take maximum of both end point.
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        return intervals.size()- k;
    }
};


class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        multiset<int> eventEndTime;
        int i =0;
        int ans = 0;
        int n = events.size();
        for(int d =1; d <=100000; ++d){
            //Delete expired event , example
            // Suppose 3 events are there  [1, 2] [1, 2] [1, 2]
            // at day 1 : attend 1st event and at day 2 attend 2md event , at day 3 , 3rd event is already expired, hence we need this kind of loop of loop to delete expired events
            while(!eventEndTime.empty() and *eventEndTime.begin() < d){
                eventEndTime.erase(eventEndTime.begin());
            }

            // put all candidate events whose start day is past the current day.
            
            //insert events if they can be start 
            while(i < n and events[i][0] <=d){
                eventEndTime.insert(events[i][1]);
                i++;
            }
            
            // we can attend 1 event on 1 day , thats why if condition not while
            // adn we attend earliest ending event first , suppose we have [1, 2] & [1, 3]
            // and we are on day=2, we should attend [1,2] first otherwise at d=3 this would be expired
            if(!eventEndTime.empty() and *eventEndTime.begin()>=d){
                ++ans;
                eventEndTime.erase(eventEndTime.begin());
            }
        }
        return ans;
    }
};


class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // Find what is the max we can reach if we start opening the tap at every ith location
        vector<int> line (1+n, 0);
        for(int i =0; i <=n; ++i){
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            line[left] = max(line[left], right);
        }
        // Sweep line
        // Lets 0th tap as best one
        int curr = line[0];
        int next_best = 0;
        int ans = 1;
        for(int i = 1; (i <=n) and (curr < n); ++i){
            // we cannot reach to this ith that means not possible at all !
            if( i > curr)
                return -1;
            else if ( i == curr){
                // curr reach its end , time to select next best
                next_best = max(next_best, line[i]);
                ++ans;
                curr = next_best; // assign next_best to curr 
                next_best =0;//rest next_best as 0
            }
            else{
                // we still are in range of curr, no need to open a new tap but keep checking what next best tap of highest range we can open next.
                next_best = max(next_best, line[i]);
            }
        }
        return ans;;
    }
};