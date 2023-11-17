package com.exercise.datajdbc.controller;

import com.exercise.datajdbc.entity.Contact;
import com.exercise.datajdbc.service.ContactService;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class AddressBookController {

    @Autowired
    private ContactService service;
    
	
	
    @PostMapping("/add")
    public String addContact(@RequestParam String name,
                             @RequestParam String surname,
                             @RequestParam String email) {
        Contact newContact = new Contact(name, surname, email);
        service.addContact(newContact);
        return "redirect:/";
    }
    
    @PostMapping("/update")
    public String updateContact(@RequestParam Long id,
                                @RequestParam("new-name") String newName,
                                @RequestParam("new-surname") String newSurname) {
        service.updateContactName(id, newName, newSurname);
        return "redirect:/";
    }

}
