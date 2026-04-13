# Report 1 Page – FIT4012 Lab 1

## 1. Mục tiêu
Tóm tắt ngắn gọn mục tiêu của bài lab.

## 2. Cách làm
- Đọc hiểu chương trình entropy mẫu.
- Bổ sung hàm tính redundancy.
- Hoàn thiện hàm mod_inverse().
- Chạy thử trên nhiều test case.

## 3. Kết quả chính
### 3.1 Entropy và redundancy
| Input | Entropy | Redundancy | Nhận xét |
|---|--------:|-----------:|---|
| aaaa |     0.0 |        8.0 |Chuỗi chỉ có 1 loại ký tự nên không có sự bất ngờ (độ bất định bằng 0). Độ dư thừa đạt mức tối đa.  |
| abcd |     2.0 |        6.0 |Các ký tự xuất hiện với xác suất bằng nhau ($1/4$). Entropy cao hơn vì mỗi ký tự đều mang thông tin mới.  |
| hello world |  2.845       | 5.155           | Chuỗi có độ phức tạp trung bình, có ký tự lặp lại ('l', 'o') và có dấu cách. Entropy tăng khi tập ký tự đa dạng hơn. |

### 3.2 Modulo inverse
| a | m | Kết quả mong đợi | Kết quả chương trình |
|---:|---:|---|----------------------|
| 3 | 7 | 5 | 5                    |
| 10 | 17 | 12 | 12                   |
| 6 | 9 | Không tồn tại | khong ton tai        |

## 4. Kết luận
Qua bài lab, em đã nắm vững cách định lượng thông tin thông qua công thức Entropy Shannon và nhận diện được mức độ dư thừa dữ liệu trong các chuỗi ký tự khác nhau. Khó khăn lớn nhất là việc xử lý các giá trị âm khi triển khai thuật toán Euclid mở rộng, đòi hỏi sự chính xác trong các phép toán modulo để tìm nghịch đảo. Điều giúp em hiểu rõ vấn đề hơn chính là việc trực tiếp quan sát sự thay đổi của các chỉ số khi thay đổi dữ liệu đầu vào, từ đó thấy được mối liên hệ chặt chẽ giữa xác suất ký tự và lượng tin, cũng như điều kiện cần và đủ ($gcd(a, m) = 1$) để một số có nghịch đảo modulo.