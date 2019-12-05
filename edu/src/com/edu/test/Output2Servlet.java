package com.edu.test;

import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/output2")
public class Output2Servlet extends HttpServlet {
	public void doPost(HttpServletRequest req, HttpServletResponse res) throws
												ServletException, IOException {
		res.setContentType("text/html;charset=UTF-8");
		PrintWriter out = res.getWriter() ;
		out.print(req.getParameter("subject"));
		out.close();
	}
}
