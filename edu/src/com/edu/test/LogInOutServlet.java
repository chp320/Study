package com.edu.test;

import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/logProc")
public class LogInOutServlet extends HttpServlet {
	public void doPost(HttpServletRequest req, HttpServletResponse res) throws
												ServletException, IOException {
		res.setContentType("text/html;charset=UTF-8");
		PrintWriter out = res.getWriter() ;
		String id = req.getParameter("id") ;
		String pwd = req.getParameter("pwd") ;
		
		if(id.isEmpty() || pwd.isEmpty()) {
			out.print("ID 또는 비밀번호를 입력해주세요.");
			return ;
		}
		
		HttpSession session = req.getSession() ;
		if(session.isNew() || session.getAttribute("id") == null) {
			session.setAttribute("id", id);
			out.print("로그인을 완료하였습니다.");
		} else {
			out.print("현재 로그인 상태입니다.");
		}
		out.close();
	}
	
	// 로그아웃 처리 - 로그아웃 시 GET방식으로 통신.
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws
												ServletException, IOException {
		res.setContentType("text/html;charset=UTF-8");
		PrintWriter out = res.getWriter() ;
		// 세션이 없는 경우 새로 생성하지 말고 null을 리턴함.
		HttpSession session = req.getSession(false) ;
		if(session != null && session.getAttribute("id") != null) {
			session.invalidate();// 세션해제
			out.print("로그아웃 작업 완료하였습니다.");
		} else {
			out.print("현재 로그인 상태가 아닙니다.") ;
		}
		out.close();
	}
}
