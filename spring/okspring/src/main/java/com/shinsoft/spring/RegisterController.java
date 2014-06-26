package com.shinsoft.spring;

import java.util.Locale;

import okjsp.User;
import okjsp.UserDAO;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

@Controller
public class RegisterController {
	@RequestMapping(value = "/register.do", method = RequestMethod.GET)
	public String register(Locale local, Model model) {
		return "register";
	}

	@RequestMapping(value = "/register.do", method = RequestMethod.POST)
	public String registerFinished(Locale local, User user, Model model) {
		if (user.getPw().equals(user.getConfirmPw())) {
			UserDAO.save(user);
			return "redirect:registerFinished.do";
		}
		model.addAttribute("msg", "password mismatched!!!");
		model.addAttribute("user", user);
		return "register";
	}

	@RequestMapping(value = "/registerFinished.do")
	public String registerFinished(Model model) {
		return "registerFinished";
	}
}
