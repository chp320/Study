package com.edu.test;

import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/dispatcher1")
public class DispatcherTest1Servlet extends HttpServlet {
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws
												ServletException, IOException {
		res.setContentType("text/html;charset=UTF-8");
		PrintWriter out = res.getWriter() ;
		out.print("<h3> Dispatcher Test1의 수행결과</h3>");
		
		ServletContext sc = this.getServletContext() ;
		RequestDispatcher rd = sc.getRequestDispatcher("/dispatcher2") ;
//		rd.forward(req, res);
		/* include() 메소드 테스트 위함 */
		rd.include(req, res);
		
		out.close();
	}
}
