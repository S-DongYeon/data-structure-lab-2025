#include <iostream>
#include <vector>
using namespace std;

//1����	�迭�� �����ϰ�, 1���� �迭�� �ִ밪�� ���ؼ� ��ȯ�ϴ� �Լ�
int findMax(const vector<int>& arr) {
	int max = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

// ���� �Լ�
int main()
{
	// �迭 ũ�� �Է� �ޱ�
	cout << "�迭�� ũ�⸦ �Է��ϼ���: ";
	int n;
	cin >> n;
	vector<int> arr(n);
	// �迭 ���� �Է� �ޱ�
	cout << "�迭�� ���Ҹ� �Է��ϼ���: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int max = findMax(arr); // �ִ밪 ã�� �Լ� ȣ��

	// ���
	cout << "�迭�� �ִ밪��: " << max << endl;
}


