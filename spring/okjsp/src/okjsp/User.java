package okjsp;

public class User {
	private String id;

	private String pw;

	private String confirmPw;

	public String getConfirmPw() {
		return confirmPw;
	}

	public void setConfirmPw(String confirmPw) {
		this.confirmPw = confirmPw;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getPw() {
		return pw;
	}

	public void setPw(String pw) {
		this.pw = pw;
	}

	public boolean isOk() {
		boolean bResult = false;
		if (id.equals("admin") && pw.equals("okpass")) {
			bResult = true;
		}
		return bResult;
	}

	public boolean isConfirmed() {
		boolean bResult = false;
		if (pw.equals(confirmPw)) {
			bResult = true;
		}
		return bResult;
	}
}
