﻿namespace DB_Uebung_3

{
    // ------------------------------------------------------------------------------ 
    //  <autogenerated> 
    //      This code was generated by a tool. 
    //      Mono Runtime Version: 4.0.30319.42000 
    //  
    //      Changes to this file may cause incorrect behavior and will be lost if  
    //      the code is regenerated. 
    //  </autogenerated> 
    // ------------------------------------------------------------------------------ 

    using System;
    using System.ComponentModel;
    using System.Diagnostics;
    using System.Xml.Serialization;
    using System.Data;
    using System.Web;
    using System.Windows;
    using System.Xml;
    


    /// CodeRemarks 
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.Web.Services", "4.6.57.0")]
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Web.Services.WebServiceBindingAttribute(Name = "DemoWSWebserviceSoap",
          Namespace = "http://tempuri.org/")]
    public partial class DemoWSWebservice : System.Web.Services.Protocols.SoapHttpClientProtocol
    {

        /// CodeRemarks 
        public DemoWSWebservice()
        {
            this.Url = "http://localhost:9000/DemoWSWebservice.asmx";
        }

        /// CodeRemarks 
        [System.Web.Services.Protocols.SoapDocumentMethodAttribute("http://tempuri.org/Query",
              RequestNamespace = "http://tempuri.org/", ResponseNamespace = "http://tempuri.org/",
              Use = System.Web.Services.Description.SoapBindingUse.Literal,
              ParameterStyle = System.Web.Services.Protocols.SoapParameterStyle.Wrapped)]
        public string Query(string sStr)
        {
            object[] results = this.Invoke("Query", new object[] {
                    sStr});
            return ((string)(results[0]));
        }

        /// CodeRemarks 
        public System.IAsyncResult BeginQuery(string sStr, System.AsyncCallback callback, object
              asyncState)
        {
            return this.BeginInvoke("Query", new object[] {
                    sStr}, callback, asyncState);
        }

        /// CodeRemarks 
        public string EndQuery(System.IAsyncResult asyncResult)
        {
            object[] results = this.EndInvoke(asyncResult);
            return ((string)(results[0]));
        }
    }


}