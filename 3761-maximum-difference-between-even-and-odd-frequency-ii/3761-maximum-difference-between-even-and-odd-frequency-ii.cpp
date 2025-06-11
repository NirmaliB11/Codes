typedef vector < int > vi;
typedef vector < vi > vvi;
typedef pair < int, int > pii;
struct DataPoint {
  int index, value, count;
};
typedef vector < DataPoint > vdp;

class Solution {
  private: void analyzePattern(const string & s, char p, char q, vi & score, vi & parityP, vi & parityQ, vi & countQ) {
    int len = s.size();
    for (int i = 0; i < len; i++) {
      int addP = (s[i] == p) ? 1 : 0;
      int addQ = (s[i] == q) ? 1 : 0;
      score[i + 1] = score[i] + addP - addQ;
      parityP[i + 1] = parityP[i] ^ addP;
      parityQ[i + 1] = parityQ[i] ^ addQ;
      countQ[i + 1] = countQ[i] + addQ;
    }
  }

  void categorizeEntries(int len,
    const vi & score,
      const vi & parityP,
        const vi & parityQ,
          const vi & countQ, vector < vdp > & groups) {
    for (int i = 0; i <= len; i++) {
      int type = (parityP[i] << 1) | parityQ[i];
      groups[type].push_back({
        i,
        score[i],
        countQ[i]
      });
    }
  }

  void processGroups(vector < vdp > & groups) {
    for (auto & grp: groups) {
      sort(grp.begin(), grp.end(), [](const DataPoint & a,
        const DataPoint & b) {
        return a.index < b.index;
      });
    }
  }

  void computeMinPrefix(const vector < vdp > & groups, vvi & minValues) {
    for (int i = 0; i < 4; i++) {
      int sz = groups[i].size();
      minValues[i].resize(sz);
      for (int j = 0; j < sz; j++) {
        minValues[i][j] = (j == 0) ? groups[i][j].value : min(minValues[i][j - 1], groups[i][j].value);
      }
    }
  }

  int determineBestOutcome(int len, int k,
    const vi & score,
      const vi & parityP,
        const vi & parityQ,
          const vi & countQ,
            const vector < vdp > & groups,
              const vvi & minValues) {
    int best = INT_MIN;
    for (int x = k; x <= len; x++) {
      if (countQ[x] < 2) continue;
      int neededType = ((1 - parityP[x]) << 1) | parityQ[x];
      int cutoff = x - k;

      auto & entries = groups[neededType];
      int pos1 = upper_bound(entries.begin(), entries.end(), cutoff, [](int v,
        const DataPoint & d) {
        return v < d.index;
      }) - entries.begin();

      if (pos1 <= 0) continue;

      int threshold = countQ[x] - 2;
      int pos2 = upper_bound(entries.begin(), entries.begin() + pos1, threshold, [](int v,
        const DataPoint & d) {
        return v < d.count;
      }) - entries.begin();

      if (pos2 <= 0) continue;

      best = max(best, score[x] - minValues[neededType][pos2 - 1]);
    }
    return best;
  }

  public: int maxDifference(string s, int k) {
    int len = s.size(), maxResult = INT_MIN;
    for (char p = '0'; p <= '4'; p++) {
      for (char q = '0'; q <= '4'; q++) {
        if (p == q) continue;

        vi score(len + 1, 0), parityP(len + 1, 0), parityQ(len + 1, 0), countQ(len + 1, 0);
        analyzePattern(s, p, q, score, parityP, parityQ, countQ);

        vector < vdp > groups(4);
        categorizeEntries(len, score, parityP, parityQ, countQ, groups);
        processGroups(groups);

        vvi minValues(4);
        computeMinPrefix(groups, minValues);

        maxResult = max(maxResult, determineBestOutcome(len, k, score, parityP, parityQ, countQ, groups, minValues));
      }
    }
    return maxResult;
  }
};