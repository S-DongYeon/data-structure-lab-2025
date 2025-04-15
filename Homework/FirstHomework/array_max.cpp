#include <iostream>
#include <vector>
using namespace std;

//1차원	배열을 선언하고, 1차원 배열의 최대값을 구해서 반환하는 함수
int findMax(const vector<int>& arr) {
	int max = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

// 메인 함수
int main()
{
	// 배열 크기 입력 받기
	cout << "배열의 크기를 입력하세요: ";
	int n;
	cin >> n;
	vector<int> arr(n);
	// 배열 원소 입력 받기
	cout << "배열의 원소를 입력하세요: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int max = findMax(arr); // 최대값 찾기 함수 호출

	// 출력
	cout << "배열의 최대값은: " << max << endl;
}


