#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

#define likely(x) __builtin_expect((x), 1)
#define unlikely(x) __builtin_expect((x), 0)
int N, M, W, K;

typedef struct __page_frame {
	int page_number;
	bool valid;
}Page_Frame;

bool search_page_fifo(vector<Page_Frame> page_frame, int page)
{
	bool search = false;
	for(int j=0;j<K;j++) {
		if(page_frame[j].valid && page_frame[j].page_number == page) {
			search = true;
			break;
		}
	}
	return search;
}
void FIFO(vector<int> page_ref, int M)
{
	vector<Page_Frame> page_frame(M, { -1, false });
	int hit_count = 0, miss_count = 0, index = 0;
	bool search = false;
	for(int i=0;i<K;i++) {
		search = search_page_fifo(page_frame, page_ref[i]);
		if(search) {
			hit_count++;
			continue;
		} 
		index = miss_count % M;
		miss_count++;
		page_frame[index] = { page_ref[i], true };
	}
	printf("====FIFO Result====\n");
	printf("Hit/Miss : %d/%d\n\n", hit_count, miss_count);
}

bool search_page_lru(vector<Page_Frame> page_frame, vector<int> &lru_count, 
						int page, int epoch)
{
	bool search = false;
	for(int j=0;j<K;j++) {
		if(page_frame[j].valid && page_frame[j].page_number == page) {
			lru_count[j] = epoch;
			search = true;
			break;
		}
	}
	return search;
}
void LRU(vector<int> page_ref, int M)
{
	vector<Page_Frame> page_frame(M, { -1, false });
	vector<int> lru_count(M, -1);
	int hit_count = 0, miss_count = 0, index = 0, num_entry = 0;
	bool search = false;
	for(int i=0;i<K;i++) {
		search = search_page_lru(page_frame, lru_count, page_ref[i], i);
		if(search) {
			hit_count++;
			continue;
		} 
		miss_count++;
		if(num_entry < M) {
			index = num_entry;
			page_frame[index] = { page_ref[i], true };
			lru_count[index] = i;
		} else {
			int min = 1500;
			for(int j=0;j<M;j++) 
				min = lru_count[j] < min ? j : min;
			index = min;
			page_frame[index] = { page_ref[i], true };
			lru_count[index] = i;
		}
		num_entry++;
	}
	printf("====LRU Result====\n");
	printf("Hit/Miss : %d/%d\n\n", hit_count, miss_count);
}

bool search_page_lfu(vector<Page_Frame> page_frame, 
						vector<int> &lru_count, vector<int> &lfu_count, 
						int page, int epoch)
{
	bool search = false;
	for(int j=0;j<K;j++) {
		if(page_frame[j].valid && page_frame[j].page_number == page) {
			lru_count[j] = epoch;
			lfu_count[j]++;
			search = true;
			break;
		}
	}
	return search;
}
void LFU(vector<int> page_ref, int M)
{
	vector<Page_Frame> page_frame(M, { -1, false });
	vector<int> lru_count(M, -1);
	vector<int> lfu_count(M, 0);
	int hit_count = 0, miss_count = 0, index = 0, num_entry = 0;
	bool search = false;
	for(int i=0;i<K;i++) {
		search = search_page_lfu(page_frame, lru_count, lfu_count, page_ref[i], i);
		if(search) {
			hit_count++;
			continue;
		} 
		miss_count++;
		if(num_entry < M) {
			index = num_entry;
			page_frame[index] = { page_ref[i], true };
			lru_count[index] = i;
			lfu_count[index]++;
		} else {
			int min = 1500;
			vector<int> min_candidate;
			for(int j=0;j<M;j++) 
				min = lfu_count[j] < min ? j : min;

			for(int j=0;j<M;j++) 
				if(lfu_count[j] == min)
					min_candidate.push_back(j);
			
			if(min_candidate.size() == 1) 
				index = min;
			else {
				int min = 1500;
				for(int j=0;j<min_candidate.size();j++) 
					min = lru_count[min_candidate[j]] < min ? j : min;
				index = min;
			}
			page_frame[index] = { page_ref[i], true };
			lru_count[index] = i;
			lfu_count[index]++;
		}
		num_entry++;
	}
	printf("====LFU Result====\n");
	printf("Hit/Miss : %d/%d\n\n", hit_count, miss_count);
}

void MIN(vector<int> page_ref, int M, int K)
{
	vector<Page_Frame> page_frame(M, { -1, false });
	map<int, int> page_map;

	for(int i=0;i<K;i++) {
		int page = page_ref[i];
		if(page_map.find(page) == page_map.end()) {
			page_map.insert(make_pair(page, 1));
			continue;
		}
		page_map.find(page)->second += 1;
	}
	map<int, int>::iterator iter;
	for(iter = page_map.begin() ; iter != page_map.end(); iter++)
		printf("%d %d\n", iter->first, iter->second);
	
	vector<int> lru_count(M, -1);
	vector<int> lfu_count(M, 0);
	int hit_count = 0, miss_count = 0, index = 0, num_entry = 0;
	bool search = false;
	for(int i=0;i<K;i++) {
		search = search_page_fifo(page_frame, page_ref[i]);
		page_map.find(page_ref[i])->second -= 1;
		printf("Current : %d\n", page_ref[i]);
		if(search) {
			printf("Hit\n");
			hit_count++;
			continue;
		} 
		printf("Miss\n");
		miss_count++;
		if(num_entry < M) {
			index = num_entry;
			page_frame[index] = { page_ref[i], true };
			lru_count[index] = i;
			lfu_count[index]++;
		} else {
			int min = 1500;
			for(iter = page_map.begin() ; iter != page_map.end(); iter++) {
				if(iter->second == 0)
					continue;
				min = iter->second < min ? iter->second : min;
				printf("nn : %d %d\n", iter->first, iter->second);
			}
			vector<int> min_candidate;
			for(iter = page_map.begin() ; iter != page_map.end(); iter++) 
				if(iter->second == min)
					min_candidate.push_back(iter->first);
			printf("Min : %d / %ld\n", min, min_candidate.size());
			for(int j=K-1; j>i; j--) {
				for(int k=0;k<min_candidate.size();k++) {
					if(page_ref[j] == min_candidate[k]) {
						index = j;
						break;
					}
				}
			}
			printf("Index maybe : %d\n", index);
		}
		num_entry++;
	}
	printf("====MIN Result====\n");
	printf("Hit/Miss : %d/%d\n\n", hit_count, miss_count);
}

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> W >> K;
	vector<int> page_ref(K, 0);
	for(int i=0;i<K;i++) 
		cin >> page_ref[i];

/*	FIFO(page_ref, M);
	LRU(page_ref, M);	
	LFU(page_ref, M);*/
	MIN(page_ref, M, K);

	return 0;
}
