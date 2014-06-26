package okjsp;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class RegisterServlet
 */
@WebServlet("/register.do")
public class RegisterServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public RegisterServlet() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doPost(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {
		User user = new User();
		// TODO check password
		// TODO check id duplication
		// TODO save
		user.setId(request.getParameter("id"));
		user.setPw(request.getParameter("pw"));
		user.setConfirmPw(request.getParameter("confirmPw"));

		if (user.getPw().equals(user.getConfirmPw())) {
			UserDAO.save(user);
			response.sendRedirect("registerFinished.jsp");
		} else {
			request.setAttribute("msg", "password mismatched!!!");
			request.getRequestDispatcher("register.jsp").forward(request,
					response);
		}
		// request.getRequestDispatcher("register.jsp").forward(request,
		// response);
	}

}
