﻿#pragma once
#include <boost/noncopyable.hpp>
#include "Point.h"
#include "LineSegment.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Color.h"

class IShape;

class CRemoteControl : boost::noncopyable
{
public:
    CRemoteControl(std::ifstream & input, std::ostream & output);
    bool HandleCommand();
    void PrintInfo() const;
private:
    bool CreateLine(std::istream & args);
    bool CreateCircle(std::istream & args);
    bool CreateRectangle(std::istream & args);
    bool CreateTriangle(std::istream & args);
    std::vector<std::string> GetTokens(std::string const& shapeSpecification) const;
private:
    typedef std::map<std::string, std::function<bool(std::istream & args)>> ActionMap;

    std::vector<std::shared_ptr<IShape>> m_shapes;
    std::ifstream & m_input;
    std::ostream & m_output;

    const ActionMap m_actionMap;
};