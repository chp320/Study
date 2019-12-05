package com.edu.test;

import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/context1")
public class ServletContextTest1Servlet extends HttpServlet {
	
//	ServletContext sc ;
//	@Override
//	public void init(ServletConfig config) throws ServletException {
//		sc = config.getServletContext() ;
//	}
	
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws
												ServletException, IOException {
		res.setContentType("text/html;charset=UTF-8");
		PrintWriter out = res.getWriter() ;
		ServletContext sc = this.getServletContext() ;
//		sc = this.getServletContext() ;
		out.print("Context: " + sc);
		out.close();
	}
}
