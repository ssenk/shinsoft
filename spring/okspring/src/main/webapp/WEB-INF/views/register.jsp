<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<style type="text/css">
.msg {
	color: #f00;
}
</style>
<meta charset="UTF-8">
<title>Welcome OKJSP</title>
</head>
<body style='font-size: 10px; font-family: "Courier New", Courier'>
	<form method="post" action="register.do"
		style='font-family: "Trebuchet MS", Sans-Serif'>
		id<input type="text" name="id"  value="${user.id}"/><br> pw<input type="password"
			name="pw" /><br> confirm<input type="password" name="confirmPw" /><br>
		<input type="submit" name="register" value="register" /> <span class="msg">
			${msg }</span>
	</form>
</body>
</html>