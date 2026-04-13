# Test cases – FIT4012 Lab 1

Đánh dấu [x] khi đã chạy và kiểm tra kết quả.

## 1. Entropy / Redundancy
- [x] Input: `aaaa` -> entropy thấp, redundancy cao
- [x] Input: `abcd` -> entropy cao hơn `aaaa`
- [x] Input: `hello world` -> entropy và redundancy được tính hợp lệ

## 2. Modulo inverse
- [x] `a=3, m=7` -> nghịch đảo modulo là 5
- [x] `a=10, m=17` -> nghịch đảo modulo là 12
- [x] `a=6, m=9` -> không tồn tại nghịch đảo modulo

## 3. Ghi chú
Thêm test riêng của nhóm nếu cần.
- [x] Input: (null) -> Entropy: 0.0, Redundancy: 0.0. (Xử lý trường hợp không có dữ liệu).
- [x] Input: aabbccdd -> Entropy: 2.0. (Tần suất xuất hiện đồng đều giữa các cặp ký tự lặp).
- [x] Input: 1234567890 -> Entropy: 3.322. (Chuỗi ký tự số không lặp lại, lượng tin cao).
- [x] Input: AaAaAa -> Entropy: 1.0. (Phân biệt chữ hoa và chữ thường, kiểm tra tính nhạy ngữ cảnh của bộ đếm).
- [x] Input: @@@### -> Entropy: 1.0. (Sử dụng ký tự đặc biệt, kết quả cho thấy Entropy chỉ phụ thuộc vào xác suất, không phụ thuộc vào loại ký tự).

- [x] a=7, m=26 -> Nghịch đảo modulo là 15. ($7 \times 15 = 105 \equiv 1 \pmod{26}$).
- [x] a=11, m=13 -> Nghịch đảo modulo là 6. ($11 \times 6 = 66 \equiv 1 \pmod{13}$).
- [x] a=2, m=10 -> Không tồn tại. ($gcd(2, 10) = 2 \neq 1$, cả hai đều là số chẵn).
- [x] a=1, m=100 -> Nghịch đảo modulo là 1. ($1 \times 1 \equiv 1 \pmod{100}$, trường hợp đặc biệt $a=1$).
- [x] a=9, m=27 -> Không tồn tại. ($gcd(9, 27) = 9 \neq 1$, $m$ là bội số của $a$).