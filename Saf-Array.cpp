void ReverseQueue() {
    if (IsEmpty()) {
        return;
    }

    int* reversedArr = new int[cap];
    int index = 0;

    // از انتهای صف به ابتدا آرایه‌ی برعکس را پر می‌کنیم
    for (int i = rear; i >= front; i--) {
        reversedArr[index++] = arr[i];
    }

    // جایگزین کردن آرایه‌ی اصلی با آرایه‌ی برعکس شده
    delete[] arr;
    arr = reversedArr;

    // به روزرسانی ایندکس‌ها
    front = 0;
    rear = size - 1;
}


};