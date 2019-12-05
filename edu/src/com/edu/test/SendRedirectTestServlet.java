package com.edu.test;

import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/portalSite")
public class SendRedirectTestServlet extends HttpServlet {
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws
												ServletException, IOException {
		String param = req.getParameter("site") ;
		if(param.equals("naver")) {
			res.sendRedirect("http://www.naver.com");
		} else if(param.equals("daum")) {
			res.sendRedirect("http://www.daum.net");
		} else if(param.equals("zum")) {
			res.sendRedirect("http://www.zum.com");
		} else if(param.equals("google")) {
			res.sendRedirect("http://www.google.com");
		}
	}
}
