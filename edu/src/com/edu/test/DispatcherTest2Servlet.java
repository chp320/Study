package com.edu.test;

import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/dispatcher2")
public class DispatcherTest2Servlet extends HttpServlet {
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws
												ServletException, IOException {
		res.setContentType("text/html;charset=UTF-8");
		PrintWriter out = res.getWriter() ;
		out.print("<h3> Dispatcher Test2의 수행결과</h3>");
		
		out.close();
	}
}
