using namespace OpcUa;

OpcUa::Node findChild(OpcUa::Node parent, std::string name) {
    try {
        std::cout << "Finding node: " << name << "\n";
        for (OpcUa::Node node : parent.GetChildren()){
            if (name == node.GetBrowseName().Name) return node;
        }
        return parent;
    } catch (const std::exception & exc){
        logger->error("Error: {}", exc.what());
        return findChild(parent, name);
    }
}

OpcUa::Variant getValue(OpcUa::Node node) {
    return node.GetAttribute(OpcUa::AttributeId::Value).Value;
}

template <typename T>
void setValue(OpcUa::Node node, T newValue) {
    try{
    	OpcUa::DataValue dataValue = node.GetAttribute(OpcUa::AttributeId::Value);
    	OpcUa::Variant value = dataValue.Value;

    	dataValue.Value = value.operator=<T>(newValue);
    	node.SetAttribute(OpcUa::AttributeId::Value, dataValue);
    } catch (const std::exception & exc){
        logger->error("Error: {}", exc.what());
        return;
    }
}

template <typename T>
void setQValue(OpcUa::Node node, OpcUa::DataValue nodeData, T newValue) {
    try{
    	nodeData.Value = nodeData.Value.operator=<T>(newValue);
    	node.SetAttribute(OpcUa::AttributeId::Value, nodeData);
    } catch(const std::exception & exc) {
        logger->error("Error: {}", exc.what());
        return;
    }
}
