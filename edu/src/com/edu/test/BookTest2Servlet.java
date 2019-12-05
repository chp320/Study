package com.edu.test;

import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/bookOutput")
public class BookTest2Servlet extends HttpServlet {
	public void doPost(HttpServletRequest req, HttpServletResponse res) throws
												ServletException, IOException {
		res.setContentType("text/html;charset=UTF-8");
		PrintWriter out = res.getWriter() ;
		
		// bookInput.html���� ���ǹ��ڿ����� POST������� ���޵�.
		// POST����� ��û������ ��ü�� ���ԵǾ� ���޵�.
		// ���� ��û���� ��ü�� �ִ� ���ڿ����� �ѱ��� ó���ϱ� ���� UTF-8 �� ���ڵ���.
		Book book = (Book)req.getAttribute("book") ;
		
		out.print("<h3>å���� : " + book.getTitle() + "</h3>");
		out.print("<h3>å���� : " + book.getAuthor() + "</h3>");
		out.print("<h3>���ǻ� : " + book.getPublisher() + "</h3>");
		
		out.close();
	}
}
