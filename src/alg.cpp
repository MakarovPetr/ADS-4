// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1;i++) {
        for (int j = i + 1;j < len;j++) {
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0;i < len - 1;i++) {
        for (int j = i + 1;j < len;j++) {
            if (arr[i] + arr[i + 1] > value)
                return count;
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    return count;
}

int cbinsearch(int* arr, int len, int value, int i) {
    int count = 0;
    int l = len;
    int r = i;
    while (r < l - 1) {
        int mid = (r + l) / 2;
        if (arr[i] + arr[mid] == value) {
            count++;
            int a = mid + 1;
            while (arr[i] + arr[a] == value && a < l) {
                count++;
                a++;
            }
            a = mid - 1;
            while (arr[i] + arr[a] == value && a > r) {
                count++;
                a--;
            }
            break;
        }
        if (arr[i] + arr[mid] > value) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        count += cbinsearch(arr, len, value, i);
    }
    return count;
}
