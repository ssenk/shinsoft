<%@ page language="java" contentType="text/html; charset=utf8"
    pageEncoding="utf8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf8">
<style type="text/css">
.msg {
	background-color: #aa0000;
}
</style>
<title>statJSONTest</title>
<script type="text/javascript" src="js/jquery-1.7.2.min.js"></script>
<script type="text/javascript">

var jqxhr = $.getJSON('./stat.do', function(j){ var message = JSON.stringify(j);
												//alert("success: " + message); 
												$('#result').html(message);
					});
</script>
</head>
<body>
안녕하세요.
<div id="result" class="msg"></div>
</body>
</html>