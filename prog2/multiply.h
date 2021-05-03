<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
<head>
  <title>Web Handin</title>
  <meta http-equiv="content-type" content="text/html; charset=iso-8859-1" />
  <style media="all" type="text/css">@import "/static/style.css";</style>
  <link rel="stylesheet" href="/static/style.css" />
  <link rel="shortcut icon" href="/static/favicon.ico" />

</head>
<body>
<div id="main">
<a href="/" class="logo"><img src="/static/logo.png"  alt="Clemson School of Computing" /></a>
  <div id="header">
    <ul id="top-navigation">

    </ul>
  </div>
  <div id="middle">
    <div id="left-column">

      <h3>Menu</h3>
      <div id="menu">
  
        
  
      </div>
  

    </div>
    <div id="center-column">
      <div class="top-bar">
        <h1>Login - with Clemson Username/Password</h1>
      </div>
      <br />
      <div class="select-bar">
        <div class="breadcrumbs">

  

        </div>
      </div>

  




<form method="post" action="/accounts/login/">
<input type='hidden' name='csrfmiddlewaretoken' value='a4UPlifqHkhIpk2f2tz69z7bhihYaFoM' />
<table>
<tr>
    <td><label for="id_username">Username:</label></td>
    <td><input id="id_username" maxlength="254" name="username" type="text" /></td>
</tr>
<tr>
    <td><label for="id_password">Password:</label></td>
    <td><input id="id_password" name="password" type="password" /></td>
</tr>
</table>

<input type="submit" value="login" />
<input type="hidden" name="next" value="/courses/2005/cpsc2310-001/assignments/PA2/estout/browse/multiply.h?raw" />
</form>

    </div>
    <div id="right-column">
      <strong class="h">INFO</strong>
      <div class="box">
        
Webhandin allows students to submit assignments, and allows instructors/graders more control. 


      </div>
    </div>
  </div>
  <div id="footer"></div>
</div>

<script type="text/javascript" src="//code.jquery.com/jquery-1.11.0.min.js"></script>
<script type="text/javascript">
$(document).ready(function(){
    $("#id_username").focus();
})
</script>

</body>
</html>
