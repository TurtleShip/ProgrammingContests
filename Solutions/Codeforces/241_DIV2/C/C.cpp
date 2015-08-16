#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Request {
	int id;
	int people;
	int pay;
	Request() {}
	Request(int i, int p, int pa) {
		id = i;
		people = p;
		pay = pa;
	}
} Request;

typedef struct Table {
	int id;
	int capacity;
	Table() {}
	Table(int i, int c) {
		id = i;
		capacity = c;
	}
} Table;

bool serveRichestSort(Request a, Request b) {
	return a.pay > b.pay;
}

bool giveSmallestFirst(Table a, Table b) {
	return a.capacity < b.capacity;
}

bool canServe(Request req, Table table) {
	return table.capacity >= req.people;
}

int main() {
	int numOfRequests, numOfTables;
	int numOfVisitors, totalPay, capacity;
	int moneyEarned = 0;
	vector< Request > requests;
	vector< Table > tables;
	vector< pair<int, int> > result;
	scanf("%d", &numOfRequests);

	for(int i=1; i <= numOfRequests; i++) {
		scanf("%d %d", &numOfVisitors, &totalPay);
		Request req(i, numOfVisitors, totalPay);
		requests.push_back( req );
	}

	scanf("%d", &numOfTables);
	bool hasServed[numOfTables];

	for(int i=1; i <= numOfTables; i++) {
		scanf("%d", &capacity);
		Table table(i, capacity);
		tables.push_back( table );
		hasServed[i] = false;
	}

	sort( requests.begin(), requests.end(), serveRichestSort );
	sort( tables.begin(), tables.end(), giveSmallestFirst );

	for(int i=0; i < requests.size(); i++) {
		bool served = false;
		for(int j=0; !served && j < tables.size(); j++) {
			if(!hasServed[tables[j].id] && canServe(requests[i], tables[j])) {
				moneyEarned += requests[i].pay;
				result.push_back( make_pair( requests[i].id, tables[j].id ));
				hasServed[ tables[j].id ] = true;
				served = true;
			}
		}
	}

	printf("%d %d\n", int(result.size()), moneyEarned);
	for(int i=0; i < result.size(); i++) {
		printf("%d %d\n", result[i].first, result[i].second );
	}

	return 0;
}