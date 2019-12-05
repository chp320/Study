package com.edu.test;

import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/cookie2")
public class CookieTest2Servlet extends HttpServlet {
	@Override
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws
												ServletException, IOException {
		res.setContentType("text/html;charset=UTF-8");
		PrintWriter out = res.getWriter() ;
		
		Cookie[] list = req.getCookies() ;
		for (int i=0; list!=null && i<list.length; i++) {
			out.println(list[i].getName() + ":" + list[i].getValue() + "<br>") ;
		}
		
		out.close();
	}
}
