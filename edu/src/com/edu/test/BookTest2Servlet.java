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
		
		// bookInput.html에서 질의문자열들은 POST방식으로 전달됨.
		// POST방식은 요청정보의 몸체에 포함되어 전달됨.
		// 따라서 요청정보 몸체에 있는 문자열들의 한글을 처리하기 위해 UTF-8 로 인코딩함.
		Book book = (Book)req.getAttribute("book") ;
		
		out.print("<h3>책제목 : " + book.getTitle() + "</h3>");
		out.print("<h3>책저자 : " + book.getAuthor() + "</h3>");
		out.print("<h3>출판사 : " + book.getPublisher() + "</h3>");
		
		out.close();
	}
}
