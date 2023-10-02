# QUẢN LÍ KHÁCH SẠN

## Mô tả

Project này hiện thực các chức năng quản lí một khách sạn

## Tính năng 

- Đặt phòng
- Quản lí khách hàng
- Quản lí nhân viên
- Dịch vụ và tiện ích
- Thanh toán
- Bảo mật và quyền truy cập
- Báo cáo và thống kê
- Quản lí và phản hồi đánh giá

## Tính năng chưa hiện thực được
- Thanh toán: hiện thực chức năng thanh toán, nhưng tiền thuê phòng được đặt cứng là 100 (do khi đặt phòng không nhập thông tin thời gian vào và ra)

## Cài đặt

1. Clone project về máy tính local
2. Mở Integrated Terminal ở folder project
3. Gõ make run trong terminal để chạy project

## Chú ý

- Các Warning khi chạy code do sử dụng biến i với kiểu dữ liệu integer để duyệt mảng khi so sánh với hàm size() trong lớp vector (có kiểu dữ liệu unsigned int)
- Thực hiện thiết lập số phòng trong chức năng "Đặt phòng" trước khi tiến hành đặt phòng
- Tài khoản và mật khẩu của quản lí:
  + Tài khoản: manager
  + Mật khẩu: admin
- Một số lựa chọn nhập số: nhập chữ sẽ bị loop chương trình
- Chức năng quản lí khách hàng: chỉ có quản lí và nhân viên RECEPTIONIST mới có thể truy cập được

