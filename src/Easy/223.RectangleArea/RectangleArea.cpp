class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        // rt1: ABCD: A-C, B-D
        // rt2: EFGH: E-G, F-H
        int srt1 = (A-C)*(B-D), srt2 = (E-G)*(F-H);
        // non-overlapped
        if (C <= E||G <= A|| B >= H||D <= F) return srt1 + srt2;
        
        // overlapped
        vector <int> h;
        h.push_back(A);
        h.push_back(C);
        h.push_back(E);
        h.push_back(G);

        vector <int> v;
        v.push_back(B);
        v.push_back(D);
        v.push_back(F);
        v.push_back(H);

        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        return srt1 + srt2 - (h[2]-h[1]) * (v[2]-v[1]);
    }
};