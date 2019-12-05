package com.edu.test;

import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/sessionTest")
public class SessionTestServlet extends HttpServlet {
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws 
											ServletException, IOException {
		res.setContentType("text/html;charset=UTF-8");
		PrintWriter out = res.getWriter() ;
		// 클라이언트로부터 전달된 질의 문자열 중 'p' 값을 추출하여 param 변수로 사용하겠다!
		// 브라우저에서 p가는 이름의 변수가 있겠군...
		String param = req.getParameter("p") ;
		String msg = null ;
		HttpSession session = null ;
		
		// 전달된 p param값에 대한 if로직 처리
		// create, delete, add, get, remove, replace를 받나보다..
		if(param.equals("create")) {
			session = req.getSession() ;
			if(session.isNew()) {	// .isNew() : req.getSession()에서 가져온 세션객체가 새로 생성된 것인지 기존 새션객체인지 판단.
				msg = "새로운 세션 객체가 생성됨" ;
			} else {
				msg = "기존의 세션 객체가 리턴됨" ;
			}
		} else if(param.equals("delete")) {
			session = req.getSession(false) ;	// 왜 이걸쓸까?? -> 세션객체가 존재하지 않으면 null을 return.
			if(session != null) {
				session.invalidate(); // 실제 세션객체 삭제
				msg = "세션 객체 삭제 작업 완료" ;
			} else {
				msg = "삭제할 세션 존재하지 않음" ;
			}
		} else if(param.equals("add")) {
			session = req.getSession(true) ;	// 왜 이걸쓸까?? -> 인자가 true.이므로 세션객체가 미존재 시 새로 생성.
			session.setAttribute("msg", "메시지입니다.") ;
			msg = "세션 객체에 데이터 등록 완료" ;			
		} else if(param.equals("get")) {
			session = req.getSession(false) ;	// 왜 이걸쓸까??
			if(session != null) {
				String str = (String) session.getAttribute("msg") ;
				msg = str ;
			} else {
				msg = "데이터를 추출할 세션 객체 존재하지 않음" ;
			}
		} else if(param.equals("remove")) {
			session = req.getSession(false) ;	// 왜 이걸쓸까??
			if(session != null) {
				session.removeAttribute("msg");
				msg = "세션 객체의 데이터 삭제 완료" ;
			} else {
				msg = "데이터를 삭제할 세션 객체 존재하지 않음" ;
			}
		} else if(param.equals("replace")) {
			session = req.getSession() ;
			session.setAttribute("msg", "새로운 메시지입니다");
			msg = "세션 객체에 데이터 등록 완료" ;
		}
		
		out.print("처리 결과 : " + msg);
		out.close();
	}
}
