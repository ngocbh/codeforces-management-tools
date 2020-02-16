# codeforces-management-tools

Một số lưu ý khi sử dụng tools, có 2 lựa chọn khi crawl:
* Mở quyền truy cập public cho contest. Nếu có quyền truy cập public thì comment ss.login() lại.
* Hoặc để sử dụng được thì cần cung cấp tên tài khoản và mật khẩu thay thế cho '********'. Mở quyền manager trên contest muốn crawl bằng tài khoản của mình. Có thể sử dụng tài khoản thay sau: '74164707NgocBH' , '123456789'

### Crawl standings
* Cung cấp contest_id hoặc contest url vào biến URLS. Contest id là 261501 trong url http://codeforces.com/group/Ir5CI6f3FD/contest/261501/...
```python
URLS = [
'261501'
]
```
* ```PENALTY=True``` , có tính thời gian nộp bài trong xếp hạng,

* ```USER_FORMAT=r'^44'``` lọc sinh viên theo lớp , '^44' là lấy các sinh viên bắt đầu bằng 44...

### Check plagiarism 
* Kết quả check trùng sẽ được lưu vào ```data/report/contestID```
* Kết quả bao gồm 3 file chính: 
* ```punishments.csv``` danh sách các sinh viên và các bài có copy code
* ```summarized_report.html``` danh sách các match giống nhau. Có thể ấn vào để kiểm tra kết quả lại bằng mắt đối với các trường hợp nghi ngờ.
* ```virtualization.png``` ảnh hình dung các bài giống nhau

### Create new standings

* Kết quả check trùng sẽ được lưu vào ```data/report/contestID```
* Các bài mà sinh viên copy của nhau trong file ```punishments.csv``` sẽ bị hạ điểm thành -1, kể cả người cho chép và người chép
* Bảng rank mới dựa trên kết quả check trùng sẽ được lưu vào ```data/report/contestID/contest-name-checked.csv```. bảng rank gốc sẽ được lưu lại vào file ```data/report/contestID/contest-name``` trong trường hợp sinh viên khiếu nại thành công với giáo viên và khôi phục điểm.

